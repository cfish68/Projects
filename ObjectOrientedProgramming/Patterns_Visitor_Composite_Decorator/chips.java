

public class chips extends HamburgerToppingDecorator{
    public chips(Hamburger hamburger)
    {
        super(hamburger);
    }

    @Override//serve the burger and decorate the burger with chips
    public String serve() {
        return super.serve() + decorateWithChips();
    }
    private String decorateWithChips(){
        return " with chips";
    }
}
