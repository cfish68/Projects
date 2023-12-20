

import java.util.Set;
import java.util.LinkedList;

// TODO: Implement Composite (change this file).
public class DirectoryDetails extends FileDetails {
    public LinkedList<FileDetails> FileDetailsComposite;

    public DirectoryDetails(String path, String name){
        super(path,name);
        FileDetailsComposite = new LinkedList<FileDetails>();
    }

    public void addFile(FileDetails fileDetails)
    {

        FileDetailsComposite.add(fileDetails);


    }


    @Override
    public void accept(FileDetailsVisitor fileDetailsVisitor)
    {
        for(FileDetails i: FileDetailsComposite)
        {
             i.accept(fileDetailsVisitor);
        }
        fileDetailsVisitor.visit(this);
    }
}