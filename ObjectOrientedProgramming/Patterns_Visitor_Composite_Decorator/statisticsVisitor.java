
public class statisticsVisitor implements FileDetailsVisitor {
    public void visit(HtmlFileDetails HtmlDetails)
    {
        System.out.println("The file " + HtmlDetails.name + " contains " + HtmlDetails.getLines() + " lines.");
    }
    public void visit(JpgFileDetails JpgDetails)
    {
        System.out.println(String.format("The picture %s has an average of %f bits per pixel.", JpgDetails.getName(), (JpgDetails.getSize() * 1.0) / (JpgDetails.getWidth()*JpgDetails.getHeight())));
    }
    public void visit(Mp3FileDetails Mp3Details)
    {
        System.out.println(String.format("The bitrate of %s is %f bytes per second.", Mp3Details.name , (Mp3Details.getSize()*1.0)/Mp3Details.getLengthSec()));
    }
    public void visit(PptxFileDetails PptxDetails)
    {
        System.out.println(String.format("The average slide size in Presentation %s is %f", PptxDetails.name, (PptxDetails.getSize()*1.0)/PptxDetails.getSlides()));
    }
    public void visit(TxtFileDetails TxtDetails)
    {
        System.out.println("The file " + TxtDetails.name + " contains " + TxtDetails.getWords() + " words.");
    }
    public void visit(DocxFileDetails DocxDetails)
    {
        System.out.println(String.format("The file %s has an average of %f words per page", DocxDetails.getName(), (DocxDetails.getWords() * 1.0) / DocxDetails.getPages()));
    }
    public void visit(DirectoryDetails directoryDetails)
    {
         FileCountVisitor cVisit = new FileCountVisitor();
        directoryDetails.accept(cVisit);

        System.out.println("Directory "+ directoryDetails.name + " has " + cVisit.count + " files.");
    }
}
