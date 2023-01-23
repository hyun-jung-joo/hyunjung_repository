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
	<%pageContext.setAttribute("multies", request.getParameterValues(s));  %>
	<c:forEach var="h" items="${multies}" varStatus="status">
		${h}/
	</c:forEach>
	<br>
</c:if>
<c:if test="${flag != 1}">
	${s} : <%=request.getParameter(s) %>
	<br>
</c:if>  
<%} %>

<hr>
<h1>Processing Parameters</h1>

<%
	String[] hobbyNames = {"뉴스", "맛집", "책", "영화", "여행"};
	String[] telCompany = {"010", "011", "017", "070"};
	String[] gNames = {"남", "여"};
	pageContext.setAttribute("hobbyNames", hobbyNames);
	pageContext.setAttribute("telCompany", telCompany);
	pageContext.setAttribute("gNames", gNames);
	int h;
 
	Enumeration<String> names2 = request.getParameterNames();
	while(names2.hasMoreElements()) {
		String s = names2.nextElement();
		pageContext.setAttribute("s", s);		
%>
	${s} :
	<c:choose>
		<c:when test="${s =='hobby'}">    
			<%pageContext.setAttribute("multies", request.getParameterValues(s));  %>
			<c:forEach var="h" items="${multies}" varStatus="status">
				${h}/
			</c:forEach>
		</c:when>   
		<c:when test="${s == 'phone1' }">
			<%pageContext.setAttribute("h", Integer.parseInt(request.getParameter(s)));  %>
			${telCompany[h] }
		</c:when>
		<c:when test="${s == 'gender' }">
			<%pageContext.setAttribute("h", Integer.parseInt(request.getParameter(s)));  %>
			${gNames[h] }
		</c:when>   
		<c:otherwise>
			<%=request.getParameter(s) %>
		</c:otherwise>
	</c:choose>
	<br>
<%		
	}
%>
</body>
</html>