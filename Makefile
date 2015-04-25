all:
	make -C LinearList/
	make -C DuLinkList/
	make -C CircleDuLinkList/
clean:
	make -C LinearList clean
	make -C DuLinkList clean
	make -C CircleDuLinkList clean
