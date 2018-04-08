package test;

import bums.BumsList;

public class Test {
    static public void main(String[] args){

        BumsList list = new BumsList();
        list.add(new Integer(123));
        list.add(new Integer(456));
        System.out.println(list.toString());
    }
}
