package controller;

import auxiliary.WorkWithDirectory;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;

public class DownloadServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("APPLICATION/OCTET-STREAM");
        resp.setCharacterEncoding("UTF-8");
        WorkWithDirectory.downloadFile("report_check_result.txt", "none", resp.getWriter());
        WorkWithDirectory.downloadFile("result.txt", "none", resp.getWriter());
        String path = req.getContextPath() + "/main";
        resp.sendRedirect(path);
    }
}
