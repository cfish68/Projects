

public class Salad extends HamburgerToppingDecorator{
    public Salad(Hamburger hamburger)
    {
        super(hamburger);
    }

    @Override
    public String serve() {
        return super.serve() + decorateWithChips();
    }
    private String decorateWithChips(){
        return " with salad";
    }
}