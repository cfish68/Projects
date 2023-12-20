

public class FileCountVisitor implements FileDetailsVisitor{
    public int count = 0;
    public void visit(HtmlFileDetails HtmlDetails)
    {
        count++;
    }
    public void visit(JpgFileDetails JpgDetails)
    {
        count++;
    }
    public void visit(Mp3FileDetails Mp3Details)
    {
        count++;
    }
    public void visit(PptxFileDetails PptxDetails)
    {
        count++;
    }
    public void visit(TxtFileDetails TxtDetails)
    {
        count++;
    }
    public void visit(DocxFileDetails DocxDetails)
    {
        count++;
    }
    public void visit(DirectoryDetails directoryDetails)
    {
        return;
    }
}
