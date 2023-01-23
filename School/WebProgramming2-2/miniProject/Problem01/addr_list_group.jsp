<%--20210815 컴퓨터학과 주현정 --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="jspbook.pb01.*"%>
<!DOCTYPE html>
<%
request.setCharacterEncoding("UTF-8");
%>
<jsp:useBean id="addr" class="jspbook.pb01.AddrBean" />
<jsp:setProperty name="addr" property="*" />
<jsp:useBean id="am" class="jspbook.pb01.AddrManager" scope="application" />

<html>
<head>
<meta charset="UTF-8">
<title>group_list</title>
</head>                                   
<body>
<div align="center">
<%
	int flag = 0;
	int groupNum = -1;
	String group = request.getParameter("group");
	if(group == null) {
		group = "그룹";	
	}
	else {
		groupNum = Integer.parseInt(group);
		group = addr.getGroupTitle2(groupNum);
		am.setKey(groupNum);
		flag = 1;
	}
%>
<h2>주소록(<%=group %>보기)</h2>
<hr>
<a href="addr_form.jsp">주소추가</a><p>
<table border=1 width=500>
<tr><td>이름</td><td>전화번호</td><td>이메일</td><td>성별</td><td>그룹</td></tr>
<%
	int i, j;
	int rpp = 2;
	int allpage;
	int size = am.getListSize();

	if(size <= rpp)
		allpage = 1;
	else if(size % rpp != 0)
		allpage = size / rpp + 1;
	else
		allpage = size / rpp;
	
	int currentPage;
	String sindex = request.getParameter("sindex");
	if(sindex == null)
		currentPage = 1;
	else
		currentPage = Integer.parseInt(sindex);
	
	AddrBean ab = null;
	int startIndex = rpp * (currentPage - 1);
	int lastIndex = startIndex + rpp;
	if(flag == 0) {
		for(j = startIndex; j < lastIndex; j++) {
			if(j >= size)
				break;
			else if(j >= 0) {
				ab = am.getAddr3(j);
			}
	%>
	<tr>
		<td><%=ab.getUsername() %></td>
		<td><%=ab.getTel() %></td>
		<td><%=ab.getEmail() %></td>
		<td><%=ab.getGender() %></td>
		<td><%=ab.getGroupTitle() %></td>
	</tr>
	<%                                          
		}	
	}
	else {
		for(AddrBean ad : am.getNewgrouplist()) {
	%>
	<tr>
		<td><%=ad.getUsername() %></td>
		<td><%=ad.getTel() %></td>
		<td><%=ad.getEmail() %></td>
		<td><%=ad.getGender() %></td>
		<td><%=ad.getGroupTitle() %></td>
	</tr>
	<%                                          
		}	
	}
%>
</table>
<%
	out.print("<input type=\"button\" value=\"전체\" onclick=\"location.href=\'addr_list_group.jsp\';\">");
	out.print(" ");
	for(i = 0; i < addr.getGroupName().length; i++){
		out.print("<input type=\"button\" value=\"" + addr.getGroupTitle2(i) + "\" onclick=\"location.href=\'addr_list_group.jsp?group=" + i + "\';\">");
		out.print(" ");
	}

	out.println("<br><br>");
	if(flag == 0) {
		for(i = 1; i <= allpage; i++) {
			if(i == currentPage) {
				out.print(i);
			}
			else { 
				out.print("<a href=\"addr_list_group.jsp?sindex=" + i + "\">" + i + "</a>");
			}
			
			if(i != allpage) {
				out.print("|");
			}
		}	
	}
%>
</div>
</body>
</html>