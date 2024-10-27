bool isSubString(string a, string b) {
    int i = 0, j = 0;
    while(i < a.length() && j < b.length()) {
        if (a[i] == b[j]) {
            i++; j++;
        } else {
            i++;
        }
    }
    if (j == b.length()) return true;
    else return false;
}