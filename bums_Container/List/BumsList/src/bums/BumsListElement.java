package bums;

/**
 * this class is used by bums.BumsList for list's element
 */
public class BumsListElement<E extends Object> {
    /**
     * field for data
     */
    private E element;
    /**
     * next object
     */
    private BumsListElement next;
    /**
     * parent object
     */
    private BumsListElement pre;
    /**
     * data index
     */
    private int index;

    /**
     * constructor with parent object and index
     * @param pre parent object
     * @param index element(data) index
     */
    public BumsListElement(BumsListElement pre, int index){
        this.pre = pre;
        this.index = index;
    }

    public String toString(String str) {
        str += "{index=" + index + ", element=" + element.toString() + "}";
        if(next != null){
            str = next.toString(str);
        }
        return str;
    }

    // getter and setters
    public void setPre(BumsListElement pre) {
        this.pre = pre;
    }

    public E getElement() {
        return element;
    }

    public void setElement(E element) {
        this.element = element;
    }

    public BumsListElement getNext() {
        return next;
    }

    public void setNext(BumsListElement next) {
        this.next = next;
    }

    public BumsListElement getPre() {
        return pre;
    }

}
