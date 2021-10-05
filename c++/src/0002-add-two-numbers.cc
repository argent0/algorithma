/**
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a
 * single digit. Add the two numbers and return the sum as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 * Definition for singly-linked list.
 *
 * Provided by the problem.
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		// faster than 59.47% of solutions
		// Even though it leaks space.
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			return addWithCarry(false, l1, l2);
		}

		ListNode* addWithCarry(bool carry, ListNode* l1, ListNode* l2) {
			int new_val = l1->val + l2->val;
			if (carry) { new_val++; }
			bool new_carry = new_val >= 10;
			if (new_carry) { new_val %= 10; }

			if (l1->next == nullptr) { //l1 stops
				if (l2->next == nullptr) { //l2 stops
					if (new_carry) {
						return new ListNode(new_val, new ListNode(1));
					} else {
						return new ListNode(new_val);
					}
				} else { //l2 continues
					return new ListNode(new_val, sumCarry(new_carry, l2->next));
				}
			} else { //l1 continues
				if (l2->next == nullptr) { //l2 stops
					return new ListNode(new_val, sumCarry(new_carry, l1->next));
				} else { //l2 continues
					return new ListNode(new_val, addWithCarry(new_carry, l1->next, l2->next));
				}
			}
		}

		// Applies a carry on a number
		ListNode* sumCarry(bool carry, ListNode* xs) {
			if (carry) { xs->val++; }
			if (xs->val < 10) {
				return xs;
			} else {
				xs->val %= 10;
				if (xs->next == nullptr) {
					return new ListNode(xs->val, new ListNode(1));
				} else {
					return new ListNode(xs->val, sumCarry(true, xs->next));
				}
			}
		}
};
