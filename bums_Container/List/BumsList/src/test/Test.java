package test;

import bums.BumsList;

/**
 * test class
 */
public class Test {
    static public void main(String[] args){

        // make instance
        BumsList<Integer> list = new BumsList<>();

        // add elements
        list.add(123);
        list.add(456);

        // test
        System.out.println(list.toString());
        System.out.println(list.get(1));
        System.out.println(list.contains(456));
        System.out.println(list.indexOf(456));
        System.out.println(list.remove(0));
        System.out.println(list.toString());
    }
}
