package controller;

import auxiliary.WorkWithDirectory;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;

@MultipartConfig
public class UploadReportServlet extends HttpServlet {
    private final long MAX_SIZE_OF_FILE_IN_BYTES = 52428800;

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Part file = req.getPart("file");

        if(file.getSize() <= MAX_SIZE_OF_FILE_IN_BYTES){
            WorkWithDirectory.uploadFile(file, "dirs/report/");
        }
        String path = req.getContextPath() + "/main";
        resp.sendRedirect(path);
    }
}
