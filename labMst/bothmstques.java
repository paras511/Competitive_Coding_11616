import java.util.*;

class bothmstques {

    // Question 2 Function

    public int maxProduct(String[] words) {
        int n = words.length;
        int[] mask = new int[n];

        for (int i = 0; i < n; i++) {
            int bitmask = 0;
            for (char c : words[i].toCharArray()) {
                bitmask |= 1 << (c - 'a');
            }
            mask[i] = bitmask;
        }

        int max = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((mask[i] & mask[j]) == 0) {
                    int product = words[i].length() * words[j].length();
                    max = Math.max(max, product);
                }
            }
        }

        return max;
    }


// Question 1 function
    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks, (a, b) -> (b[1] - b[0]) - (a[1] - a[0]));

        int a = 0;
        int cur = 0;

        for (int[] task : tasks) {
            int original = task[0];
            int min = task[1];

            if (cur < min) {
                a += (min - cur);
                cur = min;
            }

            cur -= original;
        }

        return a;
    }

    public static void main(String[] args) {

        labMst2 obj = new labMst2();

        // int[][] tasks = {{1,2},{2,4},{4,8}};
        int[][] tasks = {{1,3},{2,4},{10,11},{10,12},{8,9}};
        int effortResult = obj.minimumEffort(tasks);

        System.out.println("question1");
        System.out.println(effortResult);

        // String[] words = {"abs","abs"};
        String[] words = {"abcw","baz","foo","bar","xtnf","abcdef"};
        int productResult = obj.maxProduct(words);
        System.out.println("question2");
        System.out.println(productResult);
    }
}