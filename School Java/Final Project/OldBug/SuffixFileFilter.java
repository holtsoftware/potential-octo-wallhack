import javax.swing.filechooser.FileFilter;
import java.io.*;

    // Filter files on the given suffix.
    // The suffix may include the preceding dot.
public class SuffixFileFilter extends FileFilter {
    public SuffixFileFilter(String suffix){
        this(suffix,suffix+" files");
    }

    public SuffixFileFilter(String suffix,String description){
        // Include a leading dot.
        if(suffix.charAt(0) != '.'){
            this.suffix = "."+suffix;
        }
        else{
            this.suffix = suffix;
        }
        this.description = description;
    }

    public boolean accept(File f){
        boolean ok = false;
        if(f != null){
            final String name = f.getName();
            if(name != null){
                final int nameLength = name.length();
                int dotIndex = name.lastIndexOf(".");
                ok = (dotIndex >= 1) &&
                     getSuffix().equalsIgnoreCase(name.substring(dotIndex));
            }
        }
        return ok;
    }

    public String getDescription(){
        return description;
    }

    public String getSuffix(){
        return suffix;
    }

    private final String description, suffix;
}

