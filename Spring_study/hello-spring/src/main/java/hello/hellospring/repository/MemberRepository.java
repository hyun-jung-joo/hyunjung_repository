package hello.hellospring.repository;

import hello.hellospring.domain.Member;

import java.util.List;
import java.util.Optional;

public interface MemberRepository {
    Member save(Member member); // save
    Optional<Member> findById(Long id); // Optional->NULL 처리 방법
    Optional<Member> findByName(String name); // find
    List<Member> findAll();
}
