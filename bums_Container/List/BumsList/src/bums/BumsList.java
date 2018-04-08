package bums;

/**
 * this class is similar to list(linked list)
 */
public class BumsList {
    /**
     * size of elements
     */
    private int length=0;

    /**
     * size of capacity(count of instance)
     */
    private int capacity=1;

    /**
     * head of list capacity
     */
    private BumsListElement elStart;

    /**
     * default constructor
     * create instance of head of list capacity
     */
    public BumsList(){
        elStart = new BumsListElement(null, 0);
    }

    /**
     * add element to list
     * @param element object for addition
     * @return success or failure
     */
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

    /**
     * remove element of index
     * @param index element index to remove
     * @return removed element
     */
    public Object remove(int index){
        BumsListElement now = elStart;

        if(index < 0 || index > length){
            return null;
        }

        try{
            for(int i=0; i<index; i++) {
                now = now.getNext();
            }

            if(now.getPre() != null){
                now.getPre().setNext(now.getNext());
            } else if(index == 0) {
                elStart = now.getNext();
            }
            if(now.getNext() != null){
                now.getNext().setPre(now.getPre());
            }
        } catch(Exception e){
            return null;
        }

        return now.getElement();
    }

    /**
     * Override of toString()
     * @return string of all element
     */
    @Override
    public String toString() {
        return elStart.toString("");
    }
}
