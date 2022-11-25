public final class BSTNode<T extends Comparable<T>> {
    private T value;
    private Integer height;
    private BSTNode<T> left;
    private BSTNode<T> right;

    public static void main(String[] args) {
        BSTNode<Integer> root = new BSTNode<Integer>(12, null, null);
        root.insert( 14);
        root.insert(4);
        root.insert(8);
        root.displayInOrder();
    }

    public BSTNode(T value, BSTNode<T> left, BSTNode<T> right) {
        this.value = value;
        this.left = left;
        this.right = right;
        updateHeight();
    }

    public final void insert(T value) {
        if (value.compareTo(this.value) <= 0) {
            if (this.left != null) {
                this.left.insert(value);
            } else {
                this.left = new BSTNode<T>(value, null, null);
            }
        } else {
            if (this.right != null) {
                this.right.insert(value);
            } else {
                this.right = new BSTNode<T>(value, null, null);
            }
            updateHeight();
        }
    }

    private final void updateHeight() {
        Integer leftHeight = this.left == null ? 0 : this.left.getHeight();
        Integer rightHeight = this.right == null ? 0 : this.right.getHeight();
        this.height = Math.max(leftHeight, rightHeight) + 1;
    }

    public final Integer getHeight() {
        return this.height;
    }

    public final void displayInOrder() {
        if (this.left != null){
            this.left.displayInOrder();
        }
        System.out.printf("%s, ", this.value);
        if (this.right != null) {
            this.right.displayInOrder();
        }
    }
}