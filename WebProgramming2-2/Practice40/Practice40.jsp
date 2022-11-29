  <%--20210815 컴퓨터학과 주현정 --%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import = "java.util.Enumeration" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practice40</title>
</head>
<body>
<%
	String[] mChoices = {"hobby"};
	int flag = 0;
	Enumeration<String> names = request.getParameterNames(); 
	
	while(names.hasMoreElements()) {
		pageContext.setAttribute("flag", 0);
		String s = names.nextElement();
		pageContext.setAttribute("s", s);
		
		for(int i = 0; i < mChoices.length; i++){
			if(s.equals(mChoices[i])) {
				pageContext.setAttribute("flag", 1);
				break;
			}
		}		
%>



<c:if test="${flag == 1}">
	${s} :
	<c:set var="multies" value="${paramValues.s}" />
	<c:forEach var="h" items="${multies}" varStatus="status">
		${h}/
	</c:forEach>
	<br>
</c:if>
<c:if test="${flag != 1}">
	${s} : ${param.s}
	<br>
</c:if>
<%} %>
</body>
</html>