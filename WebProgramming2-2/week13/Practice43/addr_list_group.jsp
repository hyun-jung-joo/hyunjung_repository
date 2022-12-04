<%--20210815 컴퓨터학과 주현정 --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="jspbook.pr43.*"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<jsp:useBean id="am" class="jspbook.pr43.AddrManager" scope="application" />

<html>
<head>
<meta charset="UTF-8">
<title>group_list</title>
</head>
<body>
<div align="center">
<h2>주소록</h2>
<hr>
<a href="addr_form.jsp">주소추가</a><p>
<table border=1 width=500>
<tr><td>이름</td><td>전화번호</td><td>이메일</td><td>성별</td><td>그룹</td></tr>

<c:forEach var="ab" items="${am.getGroupList() }">
	<tr>
		<td>${ab.getUsername()}</td>
		<td>${ab.getTel()}</td>
		<td>${ab.getEmail()}</td>
		<td>${ab.getGender()}</td>
		<td>${ab.getGroupTitle()}</td>
	</tr>
</c:forEach>
</table>
</div>
</body>
</html>