<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Sharing system</title>
    <link rel="stylesheet" href="/styles/style.css">
</head>
<body>
<%--    <form action="search" method="get">--%>
<%--        <input type="search" placeholder="Поиск файла" name="searchRequest">--%>
<%--        <input type="submit" value="Search">--%>
<%--    </form>--%>

    Загрузите файл с отчетом.
    <form action="upload" method="post" enctype = "multipart/form-data">
        <input type="file" name="file" />
        <input type="submit" value="Upload" />
    </form>
    Загрузите все файлы с исходным кодом
    <form action="uploadSources" method="post" enctype = "multipart/form-data">
        <input type="file" name="file" />
        <input type="submit" value="Upload" />
    </form>
    Добавьте файл конфигурации
    <form action="uploadRule" method="post" enctype = "multipart/form-data">
        <input type="file" name="file" />
        <input type="submit" value="Upload" />
    </form>
    <form action="sharing" method="post">
        <input type="submit" value="Check">
    </form>
    <form action="download" method="get">
    <input type="submit" value="Get result">
    </form>
</body>
</html>
