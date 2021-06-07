package controller;

import auxiliary.WorkWithDirectory;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

public class Checker extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Process p = Runtime.getRuntime().exec("./../Summary/build/main -l " + WorkWithDirectory.labReport +
                " -r " + WorkWithDirectory.rulePath + " -d  dirs/sources");

        String path = req.getContextPath() + "/main";
        resp.sendRedirect(path);
    }
}
