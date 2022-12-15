package java.trees;

import java.util.HashMap;
import java.util.List;

public final class TrieNode {
    public final Character value;
    private final HashMap<Character, TrieNode> children = new HashMap<>();

    public TrieNode(Character value) {
        this.value = value;
    }

    public TrieNode(Character value, List<TrieNode> children) {
        this.value = value;
        children.forEach(node -> this.children.put(node.value, node));
    }
}
