

public class ShortRepresentationVisitor implements FileDetailsVisitor{
    public void visit(HtmlFileDetails HtmlDetails)
    {
        System.out.println(HtmlDetails.name + '\n');
    }
    public void visit(JpgFileDetails JpgDetails)
    {
        System.out.println(JpgDetails.name + '\n');
    }
    public void visit(Mp3FileDetails Mp3Details)
    {
        System.out.println(Mp3Details.name + '\n');
    }
    public void visit(PptxFileDetails PptxDetails)
    {
        System.out.println(PptxDetails.name + '\n');
    }
    public void visit(TxtFileDetails TxtDetails)
    {
        System.out.println(TxtDetails.name + '\n');
    }
    public void visit(DocxFileDetails DocxDetails)
    {
        System.out.println(DocxDetails.name + '\n');
    }
    public void visit(DirectoryDetails directoryDetails)
    {
        System.out.println(directoryDetails.name + '\n');
    }
}
