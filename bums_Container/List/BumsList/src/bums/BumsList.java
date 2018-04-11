package bums;

/**
 * this class is similar to list(linked list)
 */
public class BumsList<E extends Object> {
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
    public boolean add(E element){
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
    public E remove(int index){
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

        return (E)now.getElement();
    }

    /**
     * Override of toString()
     * @return string of all element
     */
    @Override
    public String toString() {
        return elStart.toString("");
    }

    /**
     * get element of list by index
     * @param index element's index
     * @return saved data that is at the list of index
     * @exception IndexOutOfBoundsException out of index
     */
    public E get(int index){
        if(index > length){
            throw new IndexOutOfBoundsException();
        }
        BumsListElement now = elStart;
        for(int i=0;i<index;i++){
            now = now.getNext();
            System.out.println(now.toString(""));
        }
        return (E)now.getElement();
    }

    /**
     * searching list element and return index. if it has not, return -1
     * @param target search object
     * @return index of searching object. if it has not, return -1
     */
    public int indexOf(E target){
        int result = -1;
        BumsListElement now = elStart;
        for(int i=0; i<length; i++){
            if(now.getElement().equals(target)){
                result = i;
                break;
            } else {
                now = now.getNext();
            }
        }
        return result;
    }

    /**
     * return true if this list contains the specified element
     * @param target searching element
     * @return if it has, return true. if not, false
     */
    public boolean contains(E target){
        return indexOf(target) >= 0;
    }
}
