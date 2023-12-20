

public class SizeCalculationBehavior implements FileDetailsVisitor{
    public int totalSize = 0;
    public void visit(HtmlFileDetails HtmlDetails)
    {
        totalSize += HtmlDetails.getSize();
    }
    public void visit(JpgFileDetails JpgDetails)
    {
        totalSize += JpgDetails.getSize();
    }
    public void visit(Mp3FileDetails Mp3Details)
    {
        totalSize += Mp3Details.getSize();
    }
    public void visit(PptxFileDetails PptxDetails)
    {
        totalSize += PptxDetails.getSize();
    }
    public void visit(TxtFileDetails TxtDetails)
    {
        totalSize += TxtDetails.getSize();
    }
    public void visit(DocxFileDetails DocxDetails)
    {
        totalSize += DocxDetails.getSize();
    }
    public void visit(DirectoryDetails directoryDetails)
    {
        return;
    }
}
