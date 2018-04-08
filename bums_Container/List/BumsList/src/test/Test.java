package test;

import bums.BumsList;

public class Test {
    static public void main(String[] args){

        // make instance
        BumsList list = new BumsList();

        // add elements
        list.add(new Integer(123));
        list.add(new Integer(456));
        System.out.println(list.toString());

        // remove element
        System.out.println(list.remove(0));
        System.out.println(list);
    }
}
