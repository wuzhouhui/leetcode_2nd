// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {

    private boolean flag;
    private Integer peekElem;
    private Iterator<Integer> iterator;

	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    if (iterator.hasNext()) {
            peekElem = iterator.next();
            flag = true;
        } else {
            peekElem = null;
            flag = false;
        }
        this.iterator = iterator;
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        return peekElem;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    Integer ret = peekElem;
        if (iterator.hasNext()) {
            peekElem = iterator.next();
            flag = true;
        } else {
            peekElem = null;
            flag = false;
        }
        return ret;
	}

	@Override
	public boolean hasNext() {
        return flag;
	}
}
