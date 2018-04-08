package bums;

public class BumsList {
    private int length=0;
    private int capacity=1;
    private BumsListElement elStart;

    public BumsList(){
        elStart = new BumsListElement(null, 0);
    }

    public boolean add(Object element){
        boolean result = true;
        BumsListElement now = elStart;

        try{
            while(now.getElement() != null){
                if(now.getNext() == null){
                    now.setNext(new BumsListElement(now, capacity));
                    capacity += 1;
                }
                now = now.getNext();
            }
            now.setElement(element);
            length += 1;
        } catch(Exception e){
            result = false;
        }
        return result;
    }

    @Override
    public String toString() {
        return elStart.toString("");
    }
}
