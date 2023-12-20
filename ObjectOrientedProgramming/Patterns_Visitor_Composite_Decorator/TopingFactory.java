
public class TopingFactory{
    public static Hamburger createHamburger(String code, Hamburger hamburger) {
        switch (code) {
            case "ch":
                return new chips(hamburger);
            case "or":
                return new onionRings(hamburger);
            case "sa":
                return new Salad(hamburger);
            case "fe":
                return new friedEgg(hamburger);
            default:
                throw new RuntimeException("Wrong topping");

        }
    }
}
