import java.util.Scanner;
public class leakyBucket {

	public void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int drop = 0, count = 0, mini, i;
		int inp[] = new int[25];
		System.out.print("Enter the bucket size:");
		int cap = sc.nextInt();
		System.out.print("Enter the output rate:");
		int process = sc.nextInt();
		System.out.print("Enter the number of packets:");
		int n = sc.nextInt();
		System.out.println("Enter the size of the objects to be sent:");
		for (i = 0; i < n; i++)
			inp[i] = sc.nextInt();
		System.out.println("\nSecond | Packet Received | Packet Sent | Packets Left | Packets Dropped | \n");
		System.out.println("==========================================================================");
		for (i = 0; i < n; i++) {
			count += inp[i];
			if (count > cap) {
				drop = count - cap;
				count = cap;
			}
			System.out.print(i + 1);
			System.out.print("\t\t" + inp[i]);
			mini = Math.min(count, process);
			System.out.print("\t\t" + mini);
			count -= mini;
			System.out.print("\t\t" + count);
			System.out.println("\t\t" + drop);
			drop = 0;
		}
		for (; count != 0; i++) {
			if (count > cap) {
				drop = count - cap;
				count = cap;
			}
			System.out.print(i + 1);
			System.out.print("\t\t0");
			mini = Math.min(count, process);
			System.out.print("\t\t" + mini);
			count -= mini;
			System.out.print("\t\t" + count);
			System.out.println("\t\t" + drop);
		}
		sc.close();
	}
}