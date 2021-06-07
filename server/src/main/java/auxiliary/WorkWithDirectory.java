package auxiliary;

/*
Работа с директориями пользователей
 */

import javax.servlet.http.Part;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Date;
import java.util.Random;

public class WorkWithDirectory {
    private static final String ipAddress = "192.168.43.173";
    private static final String port = ":8080";
    static final String dbPath = "/home/alex/FileSharingSystem/dataBase";
    static final String dirPath1 = "/home/alex/FileSharingSystem/dirs";
    public static final String linkTemplate =  "http://" + ipAddress + port + "/download?link=";
    public static String labReport = "none";
    public static String dirPath = "none";
    public static String rulePath = "none";

    static synchronized void writeInDB(Object message, boolean rewriteFile) throws IOException {
        BufferedWriter dataBaseWriter;

        if(rewriteFile) {
            dataBaseWriter = new BufferedWriter(new FileWriter(dbPath + "/directoriesOfUsers.txt"));
        }

        else{
            dataBaseWriter = new BufferedWriter(new FileWriter(dbPath + "/directoriesOfUsers.txt", true));
        }

        dataBaseWriter.write(message.toString());
        dataBaseWriter.close();
    }

    static synchronized void writeInLog(Object message){
        try {
            BufferedWriter logWriter = new BufferedWriter(new FileWriter(dbPath + "/log.txt", true));

            logWriter.write(new Date().toString() + " - " + message.toString() + "\n");
            logWriter.close();
        }
        catch (IOException e) {
            System.out.println(e.getMessage() + ":(");
        }
    }

    private static synchronized void writeLinkInFile(String link, String directory, String fileName, String author){
        try {
            BufferedWriter fileWriter = new BufferedWriter(new FileWriter(dbPath + "/directLinks.txt",
                    true));

            fileWriter.write(linkTemplate + link + "&" + directory + "&" + fileName + "&" + author + "\n");
            fileWriter.close();
        }
        catch (IOException e) {
            System.out.println(e.getMessage());
            writeInLog(dbPath + "/directLinks.txt In Method writeLinkInFile");
        }
    }

    private static ArrayList<String> getAllAvailableDirectoriesForUser(String user){
        ArrayList<String> res = new ArrayList<>();
        BufferedReader dataBaseReader;

        try {
            dataBaseReader = new BufferedReader(new FileReader(dbPath + "/directoriesOfUsers.txt"));
            String tmp;

            while ((tmp = dataBaseReader.readLine()) != null) {
                String[] lineFromDB;
                lineFromDB = tmp.split("&");

                if (lineFromDB[0].equals(user)) {
                    for(int i = 1; i < lineFromDB.length; i++){
                        res.add(lineFromDB[i]);
                    }
                    break;
                }
            }
        }
        catch (IOException e) {
            System.out.println(e.getMessage());
            writeInLog(dbPath + "/directoriesOfUsers.txt In method: getAllAvailableDirectoriesForUser");
        }
        return res;
    }

    public static String[] getListOfFiles(String user) {
        File userDir = new File(dirPath1 + "\\" + user);
        String[]listOfFiles = userDir.list();
        String[] result;

        try {
            result = new String[listOfFiles.length + 1];
            result[0] = user;

            System.arraycopy(listOfFiles, 0, result, 1, listOfFiles.length);
        }
        catch (NullPointerException e){
            System.out.println(e.getMessage());
            writeInLog("In method getListOfFiles. NullPointerException");

            result = new String[1];
            result[0] = "Somthing was wrong!";
        }

        return result;
    }

    public static boolean isDirectoryEmpty(String[] listOfFiles){
        return listOfFiles == null;
    }

    public static ArrayList<String> getAllAvailableDirectoriesForUserWithoutMod(String user){
        ArrayList<String> res = new ArrayList<>();
        BufferedReader dataBaseReader;

        try {
            dataBaseReader = new BufferedReader(new FileReader(dbPath + "/directoriesOfUsers.txt"));
            String tmp;

            while ((tmp = dataBaseReader.readLine()) != null) {
                String[] lineFromDB;
                lineFromDB = tmp.split("&");

                if (lineFromDB[0].equals(user)) {
                    for (int i = 1; i < lineFromDB.length; i++) {
                        res.add(lineFromDB[i].split("#")[0]);
                    }
                    break;
                }
            }
        }
        catch (IOException e) {
                writeInLog(dbPath + "/directoriesOfUsers.txt In method getAllAvailableDirectoriesForUserWithoutMod");
                System.out.println(e.getMessage());
            }
        return res;
    }

    public static void addDirectoryToUser(String directory, String user, String mod){
        BufferedReader dataBaseReader;

        try {
            dataBaseReader = new BufferedReader(new FileReader
                    (dbPath + "/directoriesOfUsers.txt"));

            String tmp;
            StringBuilder bufferOfFile = new StringBuilder();

            while ((tmp = dataBaseReader.readLine()) != null) {
                if (tmp.split("&")[0].equals(user)) {
                    StringBuilder newLine = new StringBuilder();
                    newLine.append("&").append(directory).append("#").append(mod);
                    tmp += newLine.toString();
                }
                bufferOfFile.append(tmp).append("\n");
            }
            dataBaseReader.close();

            writeInDB(bufferOfFile, true);
        }
        catch (IOException e) {
            System.out.println(e.getMessage());
            writeInLog(dbPath + "/directoriesOfUsers.txt In method addDirectoryToUser");
        }
    }

    public static boolean hasUserThisDirectory(String user, String directory){
        ArrayList<String> dirs = getAllAvailableDirectoriesForUserWithoutMod(user);

        for(String tmp : dirs){
            if(tmp.equals(directory)){
                return true;
            }
        }
        return false;
    }

    public static ArrayList<String> doSearch(String user, String searchRequest) throws IOException {
        ArrayList<String> allUserDirectories = getAllAvailableDirectoriesForUserWithoutMod(user);
        ArrayList<String> resultOfSearching = new ArrayList<>();

        dirPath = searchRequest;
//        Process p = Runtime.getRuntime().exec("./build/b/main -l /home/alex/CLionProjects/SummaryWork/Summary/resources/1.pdf" +
//                " -r /home/alex/CLionProjects/SummaryWork/Summary/resources/rule_for_kurs.json  -d " + searchRequest);


        return resultOfSearching;
    }

    public static boolean isDirectoryEditable(String user, String directory){
        ArrayList<String> dirs = getAllAvailableDirectoriesForUser(user);

        for(String tmp : dirs){
            if(tmp.split("#")[0].equals(directory) && tmp.split("#")[1].equals("readAndMod")){
                return true;
            }
        }
        return false;
    }

    public static ArrayList<String> getAllEditableDirectoryForUsers(String user){
        ArrayList<String> allDirs = getAllAvailableDirectoriesForUserWithoutMod(user);
        ArrayList<String> res = new ArrayList<>();

        for(String tmp : allDirs){
            if(isDirectoryEditable(user, tmp)){
                res.add(tmp);
            }
        }
        return res;
    }

    public static void doDelete(String file, String directory){
        File deleteFile = new File(dirPath1 +"/"+ directory +"/" + file);
        deleteFile.delete();
    }

    public static void uploadFile(Part file, String directoryForUpload) throws IOException {
//        directoryForUpload = "/home/alex/FileSharingSystem/dirs/admin/";
        String fileName = Paths.get(file.getSubmittedFileName()).getFileName().toString();

        InputStream fileContent;
        try {
            fileContent = file.getInputStream();

            File uploadedFile = new File(directoryForUpload + fileName);

            FileOutputStream out = new FileOutputStream(uploadedFile);
            out.write(fileContent.readAllBytes());
            out.close();
            fileContent.close();
        }
        catch (IOException e) {
            System.out.println("11111111");
        }
        String str = directoryForUpload + fileName;
        if(str.endsWith(".json"))
        {
            rulePath = str;
        }
        else {
            labReport = str;
        }
//        Process p = Runtime.getRuntime().exec("./build/b/main -l " + str + " -r /home/alex/CLionProjects/SummaryWork/Summary/resources/rule_for_kurs.json -d /home/alex/SummaryWork/Summary/src");
    }

    public static void downloadFile(String fileForDownload, String nameOfDir, PrintWriter writer){
        FileInputStream file;

        try {
//            file = new FileInputStream(dirPath + "/" + nameOfDir + "/" + fileForDownload);
            file = new FileInputStream(fileForDownload);
            int symbol;
            String fileName = fileForDownload;
            FileInputStream is = new FileInputStream(fileName);
            InputStreamReader isr = new InputStreamReader(is, StandardCharsets.UTF_8);
            BufferedReader buffReader = new BufferedReader(isr);
            String str;
            while ((str = buffReader.readLine()) != null) {
                writer.println(str +  System.getProperty("line.separator"));
            }

            writer.close();
            file.close();
        }
        catch (IOException e) {
            System.out.println(e.getMessage());
//            writeInLog(dirPath1 + "/" + nameOfDir + "/" + fileForDownload + " In method downloadFile");
        }
    }

    public static String[] prepareDownloadFileWithLink(String link){
        link = linkTemplate + link;
        BufferedReader dataBaseReader;
        String[] res = new String[2];

        try {
            dataBaseReader = new BufferedReader(new FileReader(dbPath + "/directLinks.txt"));
            String line;
            while((line = dataBaseReader.readLine()) != null){
                String[] tmp = line.split("&");
                if(tmp[0].equals(link)){
                    res[0] = tmp[1];//имя директории
                    res[1] = tmp[2];//имя файла
                   return res;
                }
            }
        }
        catch (IOException e){
            System.out.println(e.getMessage());
            writeInLog(new Date().toString() + dbPath + "/directLinks.txt In method downloadFileWithLink");
        }
        return res;
    }

    public static boolean hasUserThisFile(String file, String directory){
        File checkingFile = new File(dirPath1 + "/" + directory +"/" + file);

        return checkingFile.exists();
    }

    private static boolean checkValidSymbolsForLink(char ch){
        if(ch != ':' && ch != ';' && ch != '>' && ch != '<' && ch != '=' && ch != '?' && ch != '@' &&
                ch != '[' && ch != ']' && ch != '/' && ch != '^' && ch != '`'){
            return true;
        }
        return false;
    }
    public static void generateLinkKey(String directory, String fileName, String author){
        StringBuilder res = new StringBuilder();
        Random ran = new Random();
        int length = ran.nextInt(20) + 50;

        for(int i = 0; i < length; i++){
            char ch = (char)(ran.nextInt(74) + 48);
            if(checkValidSymbolsForLink(ch)) {
                res.append(ch);
            }
            else {
                i--;
            }
        }
        writeLinkInFile(res.toString(), directory, fileName, author);
    }

    public static ArrayList<String> getAllLinks(String user){
        ArrayList<String> res = new ArrayList<>();

        BufferedReader dataBaseReader;
        try {
            dataBaseReader = new BufferedReader(new FileReader(dbPath + "/directLinks.txt"));

            String tmp;
            while ((tmp = dataBaseReader.readLine()) != null) {
                String[] lineFromDB;
                lineFromDB = tmp.split("&");
                if (lineFromDB[3].equals(user)) {
                   res.add("<b> For file:" + lineFromDB[2] + "</b>\n" + lineFromDB[0]);
                }
            }
        }   catch (IOException e) {
            writeInLog(dbPath + "/directLinks.txt In method getAllLinks");
            System.out.println(e.getMessage());
        }

        return res;
    }
}
