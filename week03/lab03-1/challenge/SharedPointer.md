# Challenge: Implement a Shared Pointer

Implement a shared pointer to an `int` in a class called `SharedPointer`. The specification for `SharedPointer` is given below:

<table>
    <tr>
        <th>Method</th>
        <th>Description</th>
        <th>Usage</th>
        <th>Exceptions</th>
    </tr>
    <tr>
        <td><code>SharedPointer()</code></td>
        <td>A constructor which initialises a <code>nullptr</code>.</td>
        <td><pre><code>SharedPointer sp;</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>SharedPointer(int*)</code></td>
        <td>A constructor which initialises <code>*this</code> with <code>ptr</code>'s resource.</td>
        <td><pre><code>int* ptr{new int{42}};
SharedPointer sp(ptr);</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>~SharedPointer()</code></td>
        <td>If <code>*this</code> is the last <code>SharedPointer</code> to the resource owned by <code>*this</code>, then the resource is destroyed.</td>
        <td><pre><code>int* ptr{new int{42}};
{
    SharedPointer sp1(ptr);
    SharedPointer sp2(ptr);
    SharedPointer sp3(ptr);
}
*ptr; // Invalid access.</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>int* get()</code></td>
        <td>Returns the stored pointer.</td>
        <td><pre></code>
int* ptr1{new int{42}};
SharedPointer sp(ptr);
int* ptr2{sp.get()};</pre></code></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>long use_count()</code></td>
        <td>Returns the number of <code>SharedPointer</code> managing <code>*this</code>'s resource.</td>
        <td><pre><code>int* ptr{new int{42}};
SharedPointer sp1(ptr);
SharedPointer sp2(ptr);
SharedPointer sp3(ptr);
sp1.use_count() == 3;</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>int& operator*()</code></td>
        <td>Dereferences the stored pointer in <code>*this</code>.</td>
        <td><pre><code>int* ptr{new int{42}};
SharedPointer sp(ptr);
*sp == 42;</code></pre></td>
        <td>None</td>
    </tr>
</table>
