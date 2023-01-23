<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib tagdir="/WEB-INF/tags" prefix="ddwutag" %>
<!DOCTYPE html>
<%request.setCharacterEncoding("UTF-8");%>
<html>
<head>
<meta charset="UTF-8">
<title>Printing</title>
</head>
<body>
<%
	String id = request.getParameter("username");
	session.setAttribute("username", id);
%>
<ddwutag:greeting color="pink" />
<ddwutag:greeting color="green" />
</body>
</html>