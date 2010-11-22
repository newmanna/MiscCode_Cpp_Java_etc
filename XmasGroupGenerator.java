import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Set;
import java.util.TreeSet;

/**
 * 
 * @author nedro
 * 
 */
public class XmasGroupGenerator {

	/**
	 * # of couples
	 */
	public static final int N = 6;

	/**
	 * 
	 */
	public static void main() {
		// MultiSetOfChar pplSet = new DenseMultiSetOfChar();
		Set<Integer> s = new TreeSet<Integer>();
		List<String> buyerList = new ArrayList<String>();
		List<Integer> buyeeList = new ArrayList<Integer>();
		Random gen = new Random();

		XmasGroupGenerator.getPplList(buyerList);

		int i = 0, len = buyerList.size(), r;
		while (i < len) {
			r = gen.nextInt(len);
			if (!s.contains(r)) {
				if (i < XmasGroupGenerator.N * 2) {
					if (i % 2 == 0) {
						if (r != i && r != i + 1) {
							buyeeList.add(r);
							i++;
							s.add(r);
						}
					} else {
						if (r != i && r != i - 1) {
							buyeeList.add(r);
							i++;
							s.add(r);
						}
					}
				} else {
					if (r != i) {
						buyeeList.add(r);
						i++;
						s.add(r);
					}
				}
			}
		}

		// assertEquals("buyerList.size = buyeeList.size", buyerList.size(),
		// buyeeList.size());

		System.out.println("Who buys for who.\n");

		for (int j = 0; j < len; j++) {
			System.out.println(buyerList.get(j) + " buys for "
					+ buyerList.get(buyeeList.get(j)) + "");
		}

	}

	/**
	 * 
	 * @param l Array of people involved in the gift exchange 
	 */
	private static void getPplList(List<String> l) {
		l.add("Nathan");
		l.add("Josie");
		l.add("Steve");
		l.add("Robin");
		l.add("Bill");
		l.add("Brenda");
		l.add("Matt");
		l.add("Daisy");
		l.add("Kim");
		l.add("Amy");
		l.add("Greg");
		l.add("Cara");
		l.add("Grandma");
		l.add("Reva");
		l.add("Geoff");
	}

}
