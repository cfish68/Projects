

public class friedEgg extends HamburgerToppingDecorator{
    public friedEgg(Hamburger hamburger)
    {
        super(hamburger);
    }

    @Override
    public String serve() {
        return super.serve() + decorateWithChips();
    }
    private String decorateWithChips(){
        return " with fried egg";
    }
}