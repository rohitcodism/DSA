class EMP{
    String name;
    int id;

    EMP(String n, int i){
        this.name = n;
        this.id = i;
    }

    @Override
    public String toString(){

        return (this.name+"\n"+this.id+"\n");
    }
}

class Scientist extends EMP{

    int numPub;
    int exp;

    Scientist(String name, int id, int numPub, int exp){
        super(name, id);

        this.numPub = numPub;
        this.exp = exp;
    }

    @Override
    public String toString(){

        return (this.name+"\n"+this.id+"\n"+this.numPub+"\n"+this.exp);
    }
}

class Dscientist extends Scientist{
    int award;

    Dscientist(String name, int id, int numPub, int exp, int a){
        super(name, id, numPub, exp);

        this.award = a;
    }

    @Override
    public String toString(){

        return (this.name+"\n"+this.id+"\n"+this.numPub+"\n"+this.exp+"\n"+this.award);
    }

    public static void main(String[] args) {
        EMP e1 = new EMP("Rohit", 125);

        Scientist s1 = new Scientist("Piyush", 38, 400, 100);

        Dscientist d1 = new Dscientist("Koley", 157, 399, 102, 7);

        String x = e1.toString();

        String y = s1.toString();

        String z = d1.toString();

        System.out.println(x);

        System.out.println(y);

        System.out.println(z);
    }
}