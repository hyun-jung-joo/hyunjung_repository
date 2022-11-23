<%@ tag language="java" pageEncoding="UTF-8"%>

<%@ attribute name="brd" %>
<%@ attribute name="color" %>
<jsp:useBean id="login" class="jspbook.pr38.LoginBean" scope="page" />
<jsp:setProperty name="login" property="*" />

<style>
	table {
		text-align : center;
		width : 300px;
	}
	tr {
		height : 40px;
	}
</style>

<h1><jsp:doBody/></h1>

<table border="${brd}" bgcolor="${color}">
		<tr><td>이름 : </td><td> <%=login.getId() %></td></tr>
		<tr><td>패스워드 : </td><td><%=login.getPw() %></td></tr>
		<tr><td>이메일 : </td><td><%=login.getEmail() %></td></tr>
		<tr><td>성별 : </td><td><%=login.getGender() %></td></tr>
		<tr><td>생일 : </td><td><%=login.getBirth() %></td></tr>
<tr><td colspan=2>
<%
	out.println(login.getId() + "씨는 ");
	if(login.getGender() == 1)
		out.println("여성이고, ");
	else
		out.println("남성이고, ");
	
	if(login.isGrownUp())
		out.println("성인입니다.");
	else
		out.println("성인이 아닙니다.");
%>
</td></tr>
</table>