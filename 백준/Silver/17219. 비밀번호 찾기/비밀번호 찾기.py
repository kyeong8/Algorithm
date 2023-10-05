import sys
#sys.stdin = open('bj17219.txt', 'r')


class Node:
    def __init__(self, site=None, password=None):
        self.site = site
        self.password = password
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None

    def find_min(self):
        node = self.root
        while node.left:
            node = node.left
        return node

    def find_max(self):
        node = self.root
        while node.right:
            node = node.right
        return node

    def insert(self, site, password):
        node = Node(site, password)
        parent = None
        current = self.root

        while current:
            parent = current
            if node.site < current.site:
                current = current.left
            else:
                current = current.right

        if parent is None:
            self.root = node
        elif node.site < parent.site:
            parent.left = node
        else:
            parent.right = node

    def search(self, site):
        node = self.root
        while True:
            if node is None:
                return node
            elif node.site == site:
                return node.password
            elif site < node.site:
                node = node.left
            else:
                node = node.right

    def inorder(self):
        self._inorder(self.root)

    def _inorder(self, node):
        if node:
            self._inorder(node.left)
            print(node.data, end=' ')
            self._inorder(node.right)

    def reverse_inorder(self):
        self._reverse_inorder(self.root)

    def _reverse_inorder(self, node):
        if node:
            self._reverse_inorder(node.right)
            print(node.data, end=' ')
            self._reverse_inorder(node.left)


n, m = map(int, input().split())
tree = Tree()

for _ in range(n):
    site, password = sys.stdin.readline().split()
    tree.insert(site, password)

for _ in range(m):
    site = sys.stdin.readline().rstrip('\n')
    print(tree.search(site))


