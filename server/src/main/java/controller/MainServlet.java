package controller;

import auxiliary.WorkWithDirectory;
import auxiliary.WorkWithUsers;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.ArrayList;

public class MainServlet extends HttpServlet{
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        HttpSession session = req.getSession(false);
        String userName = "User";
        String dirPath = "C:\\java\\fileSharingSystem\\dirs\\" + userName;

        ArrayList<String> dirs = WorkWithDirectory.getAllAvailableDirectoriesForUserWithoutMod(userName); //берем все директории,
        // включая расшаренные
        String[][] userFiles = new String[dirs.size()][]; //первое измерение - имя директории (лежит в первом столбце,
        //со второго идут файлы, второе - файлы в этой директории

        for (int i = 0; i < dirs.size(); i++) {
            userFiles[i] = WorkWithDirectory.getListOfFiles(dirs.get(i));

            if (WorkWithDirectory.isDirectoryEmpty(userFiles[i])) {
                userFiles = new String[1][1];
                userFiles[0][0] = "Your disk is empty";
            }
        }

        ArrayList<String> links = WorkWithDirectory.getAllLinks(userName);

        req.setAttribute("links", links);
        req.setAttribute("files", userFiles);
        req.setAttribute("path", dirPath);
        req.setAttribute("dirs", WorkWithDirectory.getAllEditableDirectoryForUsers(userName));

        ArrayList<String> users = WorkWithUsers.getAllUsers();
        req.setAttribute("users", users);

        String path = "/index.jsp";
        ServletContext servletContext = getServletContext();
        RequestDispatcher requestDispatcher = servletContext.getRequestDispatcher(path);
        requestDispatcher.forward(req, resp);
    }
}
