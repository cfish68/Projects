

//Interface to represent visitor
public interface FileDetailsVisitor {
    public void visit(HtmlFileDetails HtmlDetails);
    public void visit(JpgFileDetails JpgDetails);
    public void visit(Mp3FileDetails Mp3Details);
    public void visit(PptxFileDetails PptxDetails);
    public void visit(TxtFileDetails TxtDetails);
    public void visit(DocxFileDetails DocxDetails);
    public void visit(DirectoryDetails directoryDetails);
}
