public class Main {

    public static void main(String[] args) {
        String url,outFile;
        url = "https://atom-installer.github.com/v1.40.1/AtomSetup-x64.exe?s=1566251845&ext=.exe";
        outFile = "AtomSetup-x64.exe";
        DManager dManager=new DManager(url,outFile);
        dManager.execute();
    }
}
