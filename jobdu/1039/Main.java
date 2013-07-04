import java.util.*;
public class Main {
    public static class UniqueNum {
        int a;
        int b;
    }

    public static int findFirstOne(int n) {
        int i = 0;
        while (((n & (1 << i)) == 0) && i < 32) {
            i++;
        }
        return i;
    }

    public static void findUniqueNum(int[] array, UniqueNum unique) {
        int m = 0;
        for (int a : array) {
            m ^= a;
        }

        int index = findFirstOne(m);
        unique.a = unique.b = 0;
        for (int a : array) {
            if ((a & (1 << index)) > 0) {
                unique.a ^= a;
            } else {
                unique.b ^= a;
            }
        }
    }

    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNextInt()) {
            int n = cin.nextInt();
            int[] array = new int[n];
            for (int i = 0; i < n; i++) {
                array[i] = cin.nextInt();
            }
            UniqueNum unique = new UniqueNum();
            findUniqueNum(array, unique);
            System.out.println(unique.a + " " + unique.b);
        }
    }
}
