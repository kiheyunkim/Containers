package bums;

public class BumsListElement {
    private Object element;
    private BumsListElement next;
    private BumsListElement pre;
    int index;

    public BumsListElement(BumsListElement pre, int index){
        this.pre = pre;
        this.index = index;
    }

    public Object getElement() {
        return element;
    }

    public void setElement(Object element) {
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

    public String toString(String str) {
        str += "{index=" + index + ", element=" + element.toString() + "}";
        if(next != null){
            str = next.toString(str);
        }
        return str;
    }
}
