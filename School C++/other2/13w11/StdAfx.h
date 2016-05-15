ostream &operator<<(ostream &output,book &dbook)
{
	output<<dbook.title<<" "<<dbook.nchapters<<" chapters, "<<dbook.npages<<" pp.";
	return output;
}
