def max_product_of_triplet(A):
    # Sort the array
    A.sort()
    
    # The largest product can be either:
    # 1. The product of the three largest numbers
    max_product1 = A[-1] * A[-2] * A[-3]
    
    # 2. The product of the two smallest numbers (could be negative) and the largest number
    max_product2 = A[0] * A[1] * A[-1]
    
    # Return the maximum of the two products
    return max(max_product1, max_product2)

# Example usage
A = [-3, 1, 2, -2, 5, 6]
result = max_product_of_triplet(A)
print("Maximum product of triplet:", result)
