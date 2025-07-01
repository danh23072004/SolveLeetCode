package project;

import java.util.ArrayList;

public class Solution {

    public class Pair {
        int number;
        int size;
        Pair(int number, int size) {
            this.number = number;
            this.size = size;
        }
    };

    private Pair getNumberFromLinkedList(ListNode list) {

        ListNode node = list;
        int result = 0;

        ArrayList<Integer> num_arr = new ArrayList<>() {};

        while (node != null) {
            num_arr.add(node.val);
            node = node.next;
        }

        int weight = (int)Math.round(Math.pow(10, num_arr.size()));

        for (int i = 0; i < num_arr.size(); i++) {
            result += num_arr.get(i) * weight;
            weight /= 10;
        }

        return new Pair(result, (int)Math.round(Math.pow(10, num_arr.size())));
    }

    private ListNode convertFromDecimalToListNode(int number) {

        int temp = number;
        int size = 1;

        while (temp != 0) {
            temp /= 10;
            size *= 10;
        }

        size /= 10;


        if (number / 10 == 0) {
            return new ListNode(number);
        }
        else {
            ListNode head = new ListNode(number / size, null);
            ListNode iterateNode = head;

            number %= size;
            size /= 10;
            while (size != 0 && number != 0) {
                ListNode newNode = new ListNode(number / size, null);

                newNode.next = head;
                head = newNode;

                number %= size;
                size /= 10;
            }
            return head;
        }

    }



    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        Pair p = getNumberFromLinkedList(l1);

        int num_1 = p.number;
        int num_2 = getNumberFromLinkedList(l2).number;

        return convertFromDecimalToListNode(num_1+num_2);
    }
}