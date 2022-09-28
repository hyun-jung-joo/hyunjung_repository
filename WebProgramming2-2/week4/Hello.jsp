<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Hello World</title>
</head>
<body>
<H2>Hello World</H2>
<HR>
현재 날짜와 시간은 : <%= java.time.LocalDateTime.now() %>
</body>
</html>