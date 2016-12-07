package com.dabaosod011.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by hai on 07/12/2016.
 */
public class FizzBuzz412 {

    private List<String> result;

    public List<String> fizzBuzz(int n) {
        result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0){
                result.add(i,"FizzBuzz");
            }
            else if ((i + 1) % 3 == 0 ){
                result.add(i,"Fizz");
            }
            else if ((i + 1) % 5 == 0 ){
                result.add(i,"Buzz");
            }else {
                result.add(i, String.valueOf(i+1));
            }
        }


        return result;
    }

    public static void main(String[] args) {

    }

}
