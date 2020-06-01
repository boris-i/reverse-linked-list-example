function list_make (str)
    local head = nil
    local prev = nil

    for i = 1, #str do
       node = {next = nil, value = string.sub(str, i, i) }

       if(head==nil) then
          head = node 
       else
          prev.next = node
       end

       prev = node 
    end

    return head 
end

function list_print (node)
    local node = node

    while node do
        io.write(node.value," -> ")
        node = node.next
    end

    io.write("\n")
end

function list_reverse(node)
    local node = node 
    local prev = nil

    while node do
        temp = node.next
        node.next = prev

        prev = node 
        node = temp
    end

    return prev
end

list = list_make("Orange!")
    
list_print(list)

list = list_reverse(list)

list_print(list)

