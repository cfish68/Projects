

public class HamburgerToppingDecorator implements Hamburger{

    private Hamburger itsHamburger;
    //
    public HamburgerToppingDecorator(Hamburger hamburger)
    {
        this.itsHamburger = hamburger;
    }
    @Override
    public String serve() {
        return itsHamburger.serve();
    }
}
