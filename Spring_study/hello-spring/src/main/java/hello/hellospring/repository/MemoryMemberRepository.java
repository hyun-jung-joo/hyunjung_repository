package hello.hellospring.repository;

import hello.hellospring.domain.Member;
import org.springframework.stereotype.Repository;

import java.sql.Array;
import java.util.*;
public class MemoryMemberRepository implements MemberRepository {

    private static Map<Long, Member> store = new HashMap<>();
    private static long sequence = 0L;

    @Override
    public Member save(Member member) {
        member.setId(++sequence); // id 세팅
        store.put(member.getId(), member); // store 에 저장
        return member;
    }

    @Override
    public Optional<Member> findById(Long id) {
        return Optional.ofNullable(store.get(id));
        // store에서 꺼내기 -> null 대비 Optional
    }

    @Override
    public Optional<Member> findByName(String name) {
        return store.values().stream()
                .filter(member -> member.getName().equals(name))
                .findAny(); // 하나라도 찾기
    }

    @Override
    public List<Member> findAll() {
        return new ArrayList<>(store.values()); // store 의 member들 반환
    }

    public void classStore() {
        store.clear();
    }
}
