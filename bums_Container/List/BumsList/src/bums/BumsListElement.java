package bums;

/**
 * this class is used by bums.BumsList for list's element
 */
class BumsListElement<E> {
    /**
     * field for data
     */
    private E element;
    /**
     * next object
     */
    private BumsListElement<E> next;
    /**
     * parent object
     */
    private BumsListElement<E> pre;
    /**
     * data index
     */
    private int index;

    /**
     * constructor with parent object and index
     * @param pre parent object
     * @param index element(data) index
     */
    BumsListElement(BumsListElement<E> pre, int index){
        this.pre = pre;
        this.index = index;
    }

    String toString(String str) {
        str += "{index=" + index + ", element=" + element.toString() + "}";
        if(next != null){
            str = next.toString(str);
        }
        return str;
    }

    // getter and setters
    void setPre(BumsListElement<E> pre) {
        this.pre = pre;
    }

    E getElement() {
        return element;
    }

    void setElement(E element) {
        this.element = element;
    }

    BumsListElement<E> getNext() {
        return next;
    }

    void setNext(BumsListElement<E> next) {
        this.next = next;
    }

    BumsListElement<E> getPre() {
        return pre;
    }

}
