# This is a Python implementation of one of the most popular caching algorithm,
# the Least Recently Used (LRU)
# The main concept here is if there is a new cache entry to be stored and the capacity
# is full, the cache container will evict the existing entry that hasn't been used the longest.

# By definition, LRU stands for least recently used, while MRU stands for most recently used.

# LRUCache is a class that represents our cache mechanism.
# An approach using python dictionary and doubly linked list is used.
# Dictionary is used as our fast access storage, while the doubly linked list is
# used to represents the LRU mechanism
class LRUCache(object):
  def __init__(self, capacity):
    self.capacity = capacity
    self.size = 0
    self.container = {}
    self.lru_node = None
    self.mru_node = None

  def get(self, key):
    # On every get calls, the fetched entry will be re-stored as the
    # most recently used (MRU) entry
    if key in self.container:
      node = self.container[key]
      self.detachNode(node)
      self.setToMRU(node)
      return node.value

    return None

  def put(self, key, value):
    if key in self.container.keys():
      # if the key already exists, just update it and put it as the MRU entry
      node = self.container[key]
      node.value = value
      self.detachNode(node)
      self.setToMRU(node)
    else:
      # key is new, check if there is a free space left
      newNode = Node(key, value, None, None)
      if self.size == self.capacity:
        # if storage is full, we have to delete the LRU entry
        self.container.pop(self.lru_node.key)
        self.detachNode(self.lru_node)
        self.size -= 1

      # after free up a space for the new entry, insert it as the MRU
      self.setToMRU(newNode)
      self.container[key] = newNode
      self.size += 1

  def setToMRU(self, node):
    node.right = self.mru_node
    node.left = None
    if self.mru_node: self.mru_node.left = node
    self.mru_node = node
    if not self.lru_node: self.lru_node = self.mru_node

  def detachNode(self, node):
    if node.left:
      node.left.right = node.right
    else:
      self.mru_node = node.right

    if node.right:
      node.right.left = node.left
    else:
      self.lru_node = node.left

  def printContainer(self):
    temp = self.mru_node
    while temp:
      print("%s=%d" % (temp.key, temp.value), end=' ')
      temp = temp.right

    print()

# Node class represents our cache entry as a doubly linked list node
class Node(object):
  def __init__(self, key, value, left, right):
    self.key = key
    self.value = value
    self.left = left
    self.right = right


def main():
  # To verify our LRU cache. Kindly give your own testcases!
  cache = LRUCache(2)
  cache.put("first-entry", 30)
  cache.put("second-entry", 10)
  cache.put("third-entry", 5)
  cache.printContainer()
  print(cache.get("second-entry"))
  cache.printContainer()
  cache.put("third-entry", 15)
  cache.printContainer()

if __name__ == "__main__":
    main()
