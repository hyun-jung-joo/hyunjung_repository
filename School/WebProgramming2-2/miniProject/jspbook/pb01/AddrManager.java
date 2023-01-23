package jspbook.pb01;

import java.util.*;

public class AddrManager{
	List<AddrBean> addrlist = new ArrayList<AddrBean>();
	List<AddrBean> grouplist = new ArrayList<AddrBean>();
	List<AddrBean> newgrouplist = new ArrayList<AddrBean>();
	int key = -1;
	
	public void add(AddrBean ab) {
		addrlist.add(ab);
		grouplist.add(ab);
	}
	
	public void groupAdd() {
		for(int i = 0; i < addrlist.size(); i++) {
			if(addrlist.get(i).getGroup() == key) {
				newgrouplist.add(addrlist.get(i));
			}
		}
	}
	
	public void setKey(int key) {
		this.key = key;
	}

	public List<AddrBean> getNewgrouplist() {
		newgrouplist.clear();
		for(int i = 0; i < addrlist.size(); i++) {
			if(addrlist.get(i).getGroup() == key) {
				newgrouplist.add(addrlist.get(i));
			}
		}
		return newgrouplist;
	}

	public void setNewgrouplist(List<AddrBean> newgrouplist) {
		this.newgrouplist = newgrouplist;
	}

	public List<AddrBean> getAddrList() {
		return addrlist;
	}
	
	public int getListSize() {
		return addrlist.size();
	}
	
	public List<AddrBean> getGroupList() {
		Collections.sort(grouplist);
		return grouplist;
	}
	
	public AddrBean getAddr(String username) {
		for(AddrBean ab : addrlist) {
			if(ab.getUsername().equals(username))
				return ab;
		}
		return null;
	}
	
	public AddrBean getAddr2(int num) {
		return addrlist.get(num);
	}
	
	public AddrBean getAddr3(int num) {
		Collections.sort(grouplist);
		return grouplist.get(num);
	}
	
	public AddrBean getAddr4(int num) {
		return newgrouplist.get(num);
	}
}
